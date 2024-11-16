import java.util.Scanner;
public class Task08 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter list: ");
		int[] list = new int[input.nextInt()];
		for (int i = 0; i < list.length; i++)
			list[i] = input.nextInt();
		input.close();
		partition(list);
		System.out.print("After the partiton, the list is ");
		for (int value: list)
			System.out.print(value + " ");
		
	}
	
	public static int partition(int[] list) {
		int index = 0;
		int[] newList = new int[list.length];
		for (int i = 1; i < list.length; i++) {
			if (list[i] <= list[0]) {
				newList[index++] = list[i];
			}
		}
		int pivotIndex = index;
		newList[index] = list[0];
		for (int i = 0; i < list.length; i++) {
			if (list[i] > list[0]) {
				newList[++index] = list[i];
			}
		}
		System.arraycopy(newList, 0, list, 0, list.length);
		return pivotIndex;
	}

}
