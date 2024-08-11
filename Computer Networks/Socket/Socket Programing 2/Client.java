package SocketLab2;

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
			
			new Thread() {
				
				public void run() {
					
					while(true) {
						System.out.println("Server: " + reader.nextLine());
					}
				};
			}.start();
			
			while(server.isConnected()) {
				writer.println(consoleInput.nextLine());
			}
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}