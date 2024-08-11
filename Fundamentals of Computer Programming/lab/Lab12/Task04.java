import java.util.*;
import java.io.*;
public class Task04 {
	public static void main(String[] args) throws Exception {
		if (args.length < 1) {
			System.out.println("Use: java Task04 sourcefile.java");
			System.exit(1);
		}
		File file = new File(args[0]);
		if (!file.exists()) {
			System.out.println("Please include the source file");
			System.exit(2);
		}
		Scanner input = new Scanner(file);
		long characters = 0L;
		int words = 0;
		int lines = 0;
		while (input.hasNext()) {
			String line = input.nextLine();
			String[] wordArray = line.split(" ");
			characters += line.length();
			words += wordArray.length;
			lines++;
		}
		input.close();
		System.out.printf("File %s has\n%d characters\n%d words\n%d lines", args[0], characters, words, lines);
		
	}

}
