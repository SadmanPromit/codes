// snake v2
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.*;
import java.util.Random;
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import javax.sound.sampled.*;
import javax.swing.*;
public class Board extends JPanel implements ActionListener {
    private final int DOT_SIZE = 10;
    private final int ALL_DOTS = 2400;
    private final int RAND_POS = 50;
    private final int x[] = new int[ALL_DOTS];
    private final int y[] = new int[ALL_DOTS];
    private int dots;
    private int score;
    private int apple_x;
    private int apple_y;
    private int DELAY;
    private int mode;
    private boolean leftDirection = false;
    private boolean rightDirection = true;
    private boolean upDirection = false;
    private boolean downDirection = false;
    private boolean inGame = true;
    private Timer timer;
    private static final String KEY = "1234567812345678"; // 16-byte key
    private JButton playAgainButton;
    public Board() {
        addKeyListener(new TAdapter());
        setBackground(Color.black);
        setFocusable(true);
        setPreferredSize(new Dimension(500, 500));
        initModeButtons();
    }
    private void initModeButtons() {
        JRadioButton easyButton = new JRadioButton("Easy");
        JRadioButton mediumButton = new JRadioButton("Medium");
        JRadioButton hardButton = new JRadioButton("Hard");
        ButtonGroup modeButtons = new ButtonGroup();
        modeButtons.add(easyButton);
        modeButtons.add(mediumButton);
        modeButtons.add(hardButton);
        add(easyButton);
        add(mediumButton);
        add(hardButton);        
        easyButton.addActionListener(e -> startGame(easyButton, mediumButton, hardButton, 180, 1));
        mediumButton.addActionListener(e -> startGame(easyButton, mediumButton, hardButton, 130, 2));
        hardButton.addActionListener(e -> startGame(easyButton, mediumButton, hardButton, 80, 3));
    }
    private void startGame(JRadioButton easyButton, JRadioButton mediumButton, JRadioButton hardButton, int delay, int mode) {
        remove(easyButton);
        remove(mediumButton);
        remove(hardButton);
        this.mode = mode;
        this.DELAY = delay;
        initGame();
    }
    private void initGame() {
        dots = 3;
        inGame = true;
        for (int z = 0; z < dots; z++) {
            x[z] = 50 - z * DOT_SIZE;
            y[z] = 50;
        }
        locateApple();
        if (playAgainButton != null) {
            remove(playAgainButton);
            playAgainButton = null;
        }
        timer = new Timer(DELAY, this);
        timer.start();
    }
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        doDrawing(g);
    }
    private void doDrawing(Graphics g) {
        if (inGame) {
            // Draw apple as a red circle
            g.setColor(Color.red);
            g.fillOval(apple_x, apple_y, DOT_SIZE, DOT_SIZE);

            // Draw snake
            for (int z = 0; z < dots; z++) {
                if (z == 0) {
                    g.setColor(Color.green);
                    g.fillRect(x[z], y[z], DOT_SIZE, DOT_SIZE);
                } else {
                    g.setColor(Color.white);
                    g.fillRect(x[z], y[z], DOT_SIZE, DOT_SIZE);
                }
            }
            Toolkit.getDefaultToolkit().sync();
        } else {
            try {
                gameOver(g);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    private void gameOver(Graphics g) throws Exception {
        int highScore = 0;
        File file = new File("db.bin");
        if (file.exists()) {
            highScore = readHighScore(file);
        } else {
            writeHighScore(file, highScore);
        }
        //new Thread(this::generateThudSound).start();	//bugged
        score = (dots - 3) * mode;
        if (score > highScore) {
            highScore = score;
            writeHighScore(file, highScore);
        }
        String msg1 = "Game Over";
        String msg2 = "Score: " + score;
        String msg3 = "High Score: " + highScore;
        Font small = new Font("Helvetica", Font.BOLD, 14);
        FontMetrics metr = getFontMetrics(small);
        g.setColor(Color.white);
        g.setFont(small);
        g.drawString(msg1, (getWidth() - metr.stringWidth(msg1)) / 2, getHeight() / 2 - 16);
        g.drawString(msg2, (getWidth() - metr.stringWidth(msg2)) / 2, getHeight() / 2);
        g.drawString(msg3, (getWidth() - metr.stringWidth(msg3)) / 2, getHeight() / 2 + 16);
        if (playAgainButton == null) {
            playAgainButton = new JButton("Play Again");
            playAgainButton.setFont(small);
            playAgainButton.setBounds((getWidth() - 130) / 2, getHeight() / 2 + 32, 130, 30);
            playAgainButton.addActionListener(e -> {				
                leftDirection = false;	// Debugged
				upDirection = false;
                rightDirection = true;
				downDirection = false;
				initGame();
			});
            setLayout(null); // Use absolute positioning for the button
            add(playAgainButton);
        }
        revalidate();
        repaint();
    }
    private int readHighScore(File file) throws Exception {
        FileInputStream fis = new FileInputStream(file);
        byte[] encryptedScore = fis.readAllBytes();
        fis.close();
        Cipher cipher = Cipher.getInstance("AES");
        SecretKeySpec keySpec = new SecretKeySpec(KEY.getBytes(), "AES");
        cipher.init(Cipher.DECRYPT_MODE, keySpec);
        byte[] decryptedScore = cipher.doFinal(encryptedScore);
        return Integer.parseInt(new String(decryptedScore).trim());
    }
    private void writeHighScore(File file, int score) throws Exception {
        Cipher cipher = Cipher.getInstance("AES");
        SecretKeySpec keySpec = new SecretKeySpec(KEY.getBytes(), "AES");
        cipher.init(Cipher.ENCRYPT_MODE, keySpec);
        byte[] encryptedScore = cipher.doFinal(String.valueOf(score).getBytes());
        FileOutputStream fos = new FileOutputStream(file);
        fos.write(encryptedScore);
        fos.close();
    }
    private void checkApple() throws Exception {
        if ((x[0] == apple_x) && (y[0] == apple_y)) {
            dots++;
            // Play apple crunching sound in a separate thread
            new Thread(this::generateCrunchSound).start();
            locateApple();
        }
    }
    private void generateCrunchSound() {
        generateSound(880, 200);
    }
    private void generateThudSound() {
        generateSound(440, 500);
    }
    private void generateSound(int hz, int msecs) {
        float SAMPLE_RATE = 44100;
        byte[] buf = new byte[1];
        AudioFormat af = new AudioFormat(SAMPLE_RATE, 8, 1, true, false);
        try (SourceDataLine sdl = AudioSystem.getSourceDataLine(af)) {
            sdl.open(af);
            sdl.start();
            for (int i = 0; i < msecs * 8; i++) {
                double angle = i / (SAMPLE_RATE / hz) * 2.0 * Math.PI;
                buf[0] = (byte) (Math.sin(angle) * 127.0);
                sdl.write(buf, 0, 1);
            }
            sdl.drain();
        } catch (LineUnavailableException ex) {
            ex.printStackTrace();
        }
    }
    private void move() {
        for (int z = dots; z > 0; z--) {
            x[z] = x[(z - 1)];
            y[z] = y[(z - 1)];
        }
        if (leftDirection)
            x[0] -= DOT_SIZE;
        if (rightDirection)
            x[0] += DOT_SIZE;
        if (upDirection)
            y[0] -= DOT_SIZE;
        if (downDirection)
            y[0] += DOT_SIZE;
    }
    private void checkCollision() {
        for (int z = dots; z > 0; z--)
            if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z]))
                inGame = false;
        if (y[0] >= getHeight())
            inGame = false;
        if (y[0] < 0)
            inGame = false;
        if (x[0] >= getWidth())
            inGame = false;
        if (x[0] < 0)
            inGame = false;
        if (!inGame)
            timer.stop();
    }
    private void locateApple() {
        Random rand = new Random();
        apple_x = rand.nextInt(RAND_POS) * DOT_SIZE;
        apple_y = rand.nextInt(RAND_POS) * DOT_SIZE;
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if (inGame) {
            try {
                checkApple();
            }
			catch (Exception e1) {
                e1.printStackTrace();
            }
            checkCollision();
            move();
        }
        repaint();
    }
    private class TAdapter extends KeyAdapter {
        @Override
        public void keyPressed(KeyEvent e) {
            int key = e.getKeyCode();
            if ((key == KeyEvent.VK_LEFT) && (!rightDirection)) {
                leftDirection = true;
                upDirection = false;
                downDirection = false;
            }
            if ((key == KeyEvent.VK_RIGHT) && (!leftDirection)) {
                rightDirection = true;
                upDirection = false;
                downDirection = false;
            }
            if ((key == KeyEvent.VK_UP) && (!downDirection)) {
                upDirection = true;
                rightDirection = false;
                leftDirection = false;
            }
            if ((key == KeyEvent.VK_DOWN) && (!upDirection)) {
                downDirection = true;
                rightDirection = false;
                leftDirection = false;
            }
        }
    }
}
