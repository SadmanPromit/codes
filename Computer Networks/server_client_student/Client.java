import java.io.BufferedReader;
import java.io.InputStreamReader; 
import java.io.PrintWriter; 
import java.net.Socket;
import java.util.Scanner;

public class Client {
	public static Socket socket = null;
	
	public static void main(String[] args) throws Exception {
		Scanner consoleInput = new Scanner(System.in);
		char loop = 'N';
		socket = new Socket("localhost", 8080);
		System.out.println("Connected to Server\n" + "Socket: " + socket.getInetAddress() + ":" + socket.getPort());
		BufferedReader in = null;
		PrintWriter out = null;
		in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		out = new PrintWriter(socket.getOutputStream(), true);
		
		do {
			System.out.println("Enter student's name: ");
			out.println(consoleInput.nextLine());
			String std_info = in.readLine();
			
//			detecting error flag
			if(!std_info.equals("298147032473298472139")) {
				System.out.println("Student's information: \n" + std_info + "\n");
				System.out.println("Do you want to check another entry?(Y/N)");
				String tempStr = consoleInput.nextLine();
				loop = tempStr.charAt(0);			
				while (loop != 'Y' && loop !=  'N' && loop != 'y' && loop !=  'n') {
					System.out.println("Wrong input\nDo you want to check another entry?(Y/N): ");
					tempStr = consoleInput.nextLine();
					loop = tempStr.charAt(0);
				}
			}
			else {
				System.out.println("Student was not found in the database. Please try again.\n");
				loop = 'Y';
			}
			out.println(loop);			
		} while(loop == 'Y' || loop == 'y');
		
		System.out.println("Closing...");
		socket.close();
		consoleInput.close();
		
	}

}
