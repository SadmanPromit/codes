import java.util.Scanner;
public class Task05 {
	public static void main(String[] args) {
		int computer = (int)(Math.random()*3);
		System.out.println("scissor (0), rock (1), paper (2): ");
		Scanner input = new Scanner(System.in);
		int player = input.nextInt();
		input.close();
		System.out.print("The computer is ");
		if (computer == 0)
			System.out.print("scissor. ");
		else if (computer == 1)
			System.out.print("rock. ");
		else
			System.out.print("paper. ");
		System.out.print("You are ");
		if (player == 0)
			System.out.print("scissor. ");
		else if (player == 1)
			System.out.print("rock. ");
		else
			System.out.print("paper. ");
		if ((player == 0 && computer == 2) || (player == 1 && computer == 0) || (player == 2 && computer == 1))
			System.out.print("You won");
		else if (player == computer)
			System.out.print("It is a draw");
		else
			System.out.print("You lost");
	}

}
