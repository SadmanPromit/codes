public class progasn2d {
	public static void main(String[] args) {
		for(int size = 16; size <= 256; size *= 2) {
			double startTime = System.nanoTime();
			int[][] A = new int[size][size], B = new int[size][size], C = new int[size][size];
			for(int i = 0; i < size; i++)
	            for(int j = 0; j < size; j++) {
	                A[i][j] = 1;//matrix A data
	                B[i][j] = 1;//matrix B data
	                C[i][j] = 0;
	            }
			for(int i = 0; i < size; i++) {
	            for(int j = 0; j < size; j++) {
	                for(int k = 0; k < size; k++)
	                    C[i][j] += (A[i][k] * B[k][j]);//matrix C multiplication calculation
	            }
	        }
			double endTime   = System.nanoTime();
			System.out.println("T(" + size + "): " + (endTime - startTime) / 1000000000 + 's');
		}
	}
}
