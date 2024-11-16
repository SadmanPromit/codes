
public class Task05 {
	public static void main(String[] args) {
		int[] number = new int[100];
		for (int i = 0; i < number.length; i++)
			number[i] = (int)(Math.random() * 10);
		int[] counts = new int[10];
		
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j < number.length; j++)
				if (number[j] == i)
					counts[i]++;
		
		for (int i = 0; i < counts.length; i++)
			System.out.println("Number of " + i + "s is: " + counts[i]);
	}

}
