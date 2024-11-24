package homeTask;

import java.io.BufferedReader;
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.io.PrintWriter; 
import java.net.Socket;
import java.util.Scanner;

public class Client {

	public static Socket socket = null;
	
	public static void main(String[] args) {
		
		System.out.println("Rock Paper Scissors Client [Version 1.02]\n(c) 2020 Sadman Sakib Khan Promit. All rights reserved.");
		
		char loop = 'N';
		Scanner consoleInput = new Scanner(System.in);
		
		try {
			socket = new Socket("localhost", 8080);
			System.out.println("Connected to Server\n" + "Socket: " + socket.getInetAddress() + ":" + socket.getPort());
		}
		catch (IOException e) {
			System.out.println("Connection to network can not be stablished\n");
		}
		
		BufferedReader in = null;
		PrintWriter out = null;			
		
		try {			
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(socket.getOutputStream(), true);
			System.out.println("Enter name: ");
			out.println(consoleInput.nextLine());
			
			do {
				System.out.println("1 is Rock, 2 is Paper and 3 is Scissors");
				System.out.println("Enter input: ");
				char tempChar = consoleInput.next().charAt(0);
				while(tempChar != '1' && tempChar != '2' && tempChar != '3') {
					System.out.println("Wrong input\nEnter input: ");
					tempChar = consoleInput.next().charAt(0);
				}
				int tempNum = tempChar - '0';
				
				out.println(tempNum);
				System.out.println("Waiting for opponent's move...");
				System.out.println("Opponent chose " + in.readLine());
				System.out.println("Winner: " + in.readLine());
				System.out.println("Do you wanna play again?(Y/N): ");
				String tempStr2 = consoleInput.next();
				loop = tempStr2.charAt(0);			
				while (loop != 'Y' && loop !=  'N' && loop != 'y' && loop !=  'n') {
					System.out.println("Wrong input\nDo you wanna play again?(Y/N): ");
					tempStr2 = consoleInput.next();
					loop = tempStr2.charAt(0);
				}
				out.println(loop);
			} while(loop == 'Y' || loop == 'y');			
			
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		consoleInput.close();	
	}
}
