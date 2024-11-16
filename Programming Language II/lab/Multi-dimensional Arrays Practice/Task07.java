import java.util.Scanner;
public class Task07 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter list1: ");
		int[] list1 = new int[input.nextInt()];
		for (int i = 0; i < list1.length; i++)
			list1[i] = input.nextInt();
		System.out.println("Enter list2: ");
		int[] list2 = new int[input.nextInt()];
		for (int i = 0; i < list2.length; i++)
			list2[i] = input.nextInt();
		input.close();
		int[] newList = merge(list1, list2);
		System.out.print("The merged list is ");
		for (int value: newList)
			System.out.print(value + " ");
	}
	
	public static int[] merge(int[] list1, int[] list2) {
		int[] newList = new int[list1.length + list2.length];
		for (int i = 0; i < list1.length; i++)
			newList[i] = list1[i];
		for (int i = 0, j = list1.length; i < list2.length; i++, j++)
			newList[j] = list2[i];
		sort(newList);
		return newList;
	}
	
	public static void sort(int[] list) {
		for (int i = 0; i < list.length - 1; i++)
			for (int j = 0; j < list.length - i - 1; j++)
				if (list[j] > list[j + 1]) {
					int temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
	}

}
