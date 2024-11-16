import java.util.Scanner;
public class Task08 {
	public static void main(String[] args) {
		System.out.println("Enter list1: ");
		Scanner input = new Scanner(System.in);
		int[] list1 = new int[input.nextInt()];
		for (int i = 0; i < list1.length; i++)
			list1[i] = input.nextInt();
		System.out.println("Enter list2: ");
		int[] list2 = new int[input.nextInt()];
		for (int i = 0; i < list2.length; i++)
			list2[i] = input.nextInt();
		input.close();
		System.out.println("Two lists are" + (equals(list1, list2) ? " " : " not ") + "identical");
	}
	
	public static boolean equals(int[] list1, int[] list2) {
		if (list1.length != list2.length)
			return false;
		bubbleSort(list1);
		bubbleSort(list2);
		for (int i = 0; i < list1.length; i++)
				if (list1[i] != list2[i])
					return false;
		return true;
	}
	
	public static void bubbleSort(int[] list) {
		for (int i = 0; i < list.length - 1; i++)
			for (int j = 0; j < list.length - i - 1; j++)
				if (list[j] > list[j + 1]) {
					int temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
	}

}
