import java.util.Scanner;
import java.util.ArrayList;
public class Task04 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter five integers for list1: ");
		ArrayList<Integer> list1 = new ArrayList<>();
		for (int i = 0; i < 5; i++)
			list1.add(input.nextInt());
		System.out.println("Enter five integers for list2: ");
		ArrayList<Integer> list2 = new ArrayList<>();
		for (int i = 0; i < 5; i++)
			list2.add(input.nextInt());
		input.close();
		System.out.println("The combined list is " + union(list1, list2));
	}
	public static ArrayList<Integer> union(ArrayList<Integer> list1, ArrayList<Integer> list2) {
		ArrayList<Integer> newList = new ArrayList<>();
		newList.addAll(list1);
		newList.addAll(list2);
		return newList;
	}

}
