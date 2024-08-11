import java.util.*;
import java.io.*;
public class Task05 {
	public static void main(String[] args ) throws Exception{
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the file: ");
		File file = new File(input.nextLine());
		if (!file.exists()) {
			System.out.println("scores text file is missing");
			System.exit(1);
		}
		input.close();
		Scanner inputFile = new Scanner(file);
		int total = 0;
		int count = 0;
		while (inputFile.hasNext()) {
			int score = inputFile.nextInt();
			total += score;
			count++;
		}
		inputFile.close();
		double average = (double)total / count;
		System.out.println("Total score: " + total + " and average score: " + average);
		
	}

}
