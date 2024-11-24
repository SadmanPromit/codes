// snake v2
import javax.swing.JFrame;
public class SnakeGame extends JFrame {
    public SnakeGame() {
        initUI();
    }
    private void initUI() {
        add(new Board());
        setResizable(false);
        pack();        
        setTitle("Snake Game");
        setLocationRelativeTo(null); // Center the window
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                JFrame ex = new SnakeGame();
                ex.setVisible(true);
            }
        });
    }
}
