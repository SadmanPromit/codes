package homeTask;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class Client {
	
	public static void main(String[] args) {
		
		try {			
			Socket server = new Socket("localhost", 20);
			Scanner reader = new Scanner(server.getInputStream());
			PrintWriter writer = new PrintWriter(server.getOutputStream(), true);
			Scanner consoleInput = new Scanner(System.in);
			
//			input name
			System.out.println("Enter name: ");
			writer.println(consoleInput.nextLine());
			
			new Thread() {				
				public void run() {					
					while(true) {						
						System.out.println("Question: " + reader.nextLine());
						System.out.println("Enter answer: ");
						writer.println(consoleInput.nextLine());
						
//						getting champ
						System.out.println(reader.nextLine());
					}
				};
			}.start();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}