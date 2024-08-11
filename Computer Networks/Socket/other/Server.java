import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.LinkedList;

public class Server {
	private static ServerSocket server = null;
	private static Socket socket = null;
	private static final int port = 8080;
	public static LinkedList<Student> studentList = new LinkedList<>();
	//this database can store unlimited student entries
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = null;
		PrintWriter out = null;
		char loop1 = 'N';
		char loop2 = 'N';
		boolean ifFound = false;
		
//		start server
		System.out.println("Server is starting ...");
		server = new ServerSocket(port);
		System.out.println("Server has started");
		
//		populating the database
		Scanner consoleInput = new Scanner(System.in);
		System.out.println("Enter students' data...");		
		do {
//			creating a student object and setting null to its fields initially
			studentList.add(new Student(null, null, null, null, null));
			System.out.println("Enter Student's Name: ");
			studentList.getLast().name = consoleInput.nextLine();
			System.out.println("Enter Student's ID: ");
			studentList.getLast().id = consoleInput.nextLine();
			System.out.println("Enter Student's Department: ");
			studentList.getLast().department = consoleInput.nextLine();
			System.out.println("Enter Student's Curriculum: ");
			studentList.getLast().curriculum = consoleInput.nextLine();
			System.out.println("Enter Student's Contact Number: ");
			studentList.getLast().contactNo = consoleInput.nextLine();
			System.out.println("Add another entry?(Y/N)");
			String tempStr = consoleInput.nextLine();
			loop1 = tempStr.charAt(0);			
			while (loop1 != 'Y' && loop1 !=  'N' && loop1 != 'y' && loop1 !=  'n') {
				System.out.println("Wrong input\nDo you wanna add another entry?(Y/N): ");
				tempStr = consoleInput.nextLine();
				loop1 = tempStr.charAt(0);
			}
		} while(loop1 == 'Y' || loop1 == 'y');		
		consoleInput.close();
		
//		sending info to client
		while(!server.isClosed()) {
			System.out.println("Waiting for client...");
			socket = server.accept();
			System.out.println("Client has been connected");
			in = new BufferedReader( new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(socket.getOutputStream(), true);
			do {
				String std_name = in.readLine();
				for(int i = 0; i < studentList.size(); i++) {
					if(std_name.equals(studentList.get(i).name)) {
						out.println(studentList.get(i).info());
						ifFound = true;
						break;
					}
				}
				System.out.println("Sending info to client...");
				if(!ifFound)
					out.println("298147032473298472139");/*this is the error flag*/
				ifFound = false;				
				loop2 = in.readLine().charAt(0);
			} while(loop2 == 'Y' || loop2 == 'y');
			System.out.println("Client left");
			socket.close();
		}

	}

}

//creating student object
class Student {
	public String name, id, department, curriculum, contactNo;
	
	public Student(String name, String id, String department, String curriculum, String contactNo) {
		this.name = name;
		this.id = id;
		this.department = department;
		this.curriculum = curriculum;
		this.contactNo = contactNo;
	}
	
//	this method concatenate students info altogether
	public String info() {
		return "Student's Name: " + name + ", ID: " + id + ", Department: " + department + ", Curriculum: " + curriculum + ", Contact Number: " + contactNo;
	}
	
}
