package homeTask;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;
import java.util.Scanner;

public class Server {
//	this program can accept unlimited clients.
	public static LinkedList<clientThread> clientList = new LinkedList<>();
	static int high = 0;
	static String champ = "";
	static Thread[] t;
	public static void main(String[] args) {
				
		try {			
			ServerSocket serverSocket = new ServerSocket(20);
			System.out.println("Server Started");
			System.out.println("Waiting for clients.");
			new Thread() {				
				@Override
				public void run() {					
					super.run();
					Scanner consoleInput = new Scanner(System.in);
					
					while(true) {
						System.out.println("Enter question: ");
						String qs = consoleInput.nextLine();
						
//						sending question to clients						
						for (int i = 0; i < clientList.size(); i++) {
							clientList.get(i).writer.println(qs);
						}
						
//						getting answers from clients
						t = new Thread[clientList.size()];					
						for (int i = 0; i < clientList.size(); i++) {
							final int temp = i;
							t[i] = new Thread() {
								public void run() {
//									This program uses blocking IO api. That's why the server needs all the connected clients answers to get the output. The program would be much more responsive if Non Blocking IO(Java NIO) api was used. Selectors would do the work. 
									System.out.println(clientList.get(temp).name + " answered: " + clientList.get(temp).reader.nextLine()); /*Blocking IO blocks the thread until answer are received*/
									System.out.println("Enter 'Y' to mark. 'N' to continue.");
									char tempChar = consoleInput.nextLine().charAt(0);
									while(tempChar != 'Y' && tempChar != 'y' && tempChar != 'N' && tempChar != 'n') {
										System.out.println("Wrong input\nEnter again: ");
										tempChar = consoleInput.nextLine().charAt(0);
									}
									
									if(tempChar == 'Y' || tempChar == 'y') {
										clientList.get(temp).score++;
										for (int j = 0; j < clientList.size() && j != temp; j++) {
											t[j].interrupt();
										}
										
									}																	
								}
							};
							t[i].start();
						}
									
						for (int i = 0; i < clientList.size(); i++) {
							try {
								t[i].join();
							} catch (InterruptedException e) {
								e.printStackTrace();
							}
						}
						
//						Scoring
						for (int i = 0; i < clientList.size(); i++) {
							if(high < clientList.get(i).score) {
								high = clientList.get(i).score;
								champ = clientList.get(i).name;
							}
						}
						
//						sending champ
						for (int i = 0; i < clientList.size(); i++) {
							clientList.get(i).writer.println("Current math champ: " + champ + "(" + high + ")");
						}
					}
				}
			}.start();
			
			while(true) {
				clientList.add(new clientThread(serverSocket.accept()));
				clientList.peekLast().name = clientList.peekLast().reader.nextLine();
				System.out.println(clientList.peekLast().name + " joined.");
				clientList.peekLast().start();
			}
		} catch (IOException e) {
			System.out.println("Sorry! Can not start the server");
		}
	}
}

class clientThread extends Thread {
	
	Socket clientSocket;
	Scanner reader;
	PrintWriter writer;
	int score;
	String name;
	
	public clientThread(Socket clientSocket) throws IOException {
		
		this.clientSocket = clientSocket;
		this.reader = new Scanner(clientSocket.getInputStream());
		this.writer = new PrintWriter(clientSocket.getOutputStream(), true);
		this.score = 0;
		this.name = "";
	}
	
	@Override
	public void run() {
		
		try {
			
			while(clientSocket.isConnected()) {
//				online
			}
		} catch (Exception e) {
			System.out.println("Client Left");
		}
		Server.clientList.remove(this);
	}
}