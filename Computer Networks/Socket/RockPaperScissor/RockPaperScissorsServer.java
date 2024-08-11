package homeTask;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class RockPaperScissorsServer {
	
	private static ServerSocket server = null;
	private static Socket socket1 = null;
	private static Socket socket2 = null;
	private static final int port = 8080;
	private static String player1Name = "";
	private static String player2Name = "";
	private static int player1Input = 0;
	private static int player2Input = 0;
	private static String winner = "";
	
	public static void main(String[] args) throws Exception {
		
		System.out.println("Rock Paper Scissors Server [Version 1.02]\n(c) 2020 Sadman Sakib Khan Promit. All rights reserved.");
		
		//Create IO Objects
		BufferedReader in1 = null;
		BufferedReader in2 = null;
		PrintWriter out1 = null;
		PrintWriter out2 = null;
		char nextGame1 = 'N';
		char nextGame2 = 'N';

		//Start Server
		System.out.println("Server is starting ...");
		server = new ServerSocket(port);
		System.out.println("Server has started");		
		System.out.println("Waiting for players...");
		
		while(!server.isClosed()) {
			
			if(nextGame1 == 'N'|| nextGame1 == 'n') {
				socket1 = server.accept();
				System.out.println("Player1 has been connected");		
				in1 = new BufferedReader( new InputStreamReader(socket1.getInputStream()));
				out1 = new PrintWriter(socket1.getOutputStream(), true);
				nextGame1 = 'Y';
				player1Name = in1.readLine();
			}
			
			if(nextGame2 == 'N'|| nextGame2 == 'n') {
				socket2 = server.accept();
				System.out.println("Player2 has been connected");			
				in2 = new BufferedReader( new InputStreamReader(socket2.getInputStream()));
				out2 = new PrintWriter(socket2.getOutputStream(), true);
				nextGame2 = 'Y';
				player2Name = in2.readLine();
			}			
								
			while((nextGame1 == 'Y' || nextGame1 == 'y') && (nextGame2 == 'Y' || nextGame2 == 'y')) {
				player1Input = Integer.parseInt(in1.readLine());					
				player2Input = Integer.parseInt(in2.readLine());
				out1.println(player2Input);
				out2.println(player1Input);
				System.out.println(player1Name + "chose: " + player1Input);
				System.out.println(player2Name + "chose: " + player2Input);
				
				//game logic
				if(player1Input == player2Input)
					winner = "It's a Draw!";
				else if((player1Input == 1 && player2Input == 3) || (player1Input == 2 && player2Input == 1) || (player1Input == 3 && player2Input == 2))
					winner = player1Name;
				else
					winner = player2Name;
				
				out1.println(winner);
				out2.println(winner);			
				System.out.println("Winner: " + winner);
				
				nextGame1 = in1.readLine().charAt(0);
				nextGame2 = in2.readLine().charAt(0);
				if(nextGame1 == 'N' || nextGame1 == 'n') {
					socket1.close();
					in1.close();
					out1.close();
					System.out.println(player1Name + " left");
				}
					
				if(nextGame2 == 'N' || nextGame2 == 'n') {
					socket2.close();
					in2.close();
					out2.close();
					System.out.println(player2Name + " left");
				}					
			}					
		}
		
	}
}