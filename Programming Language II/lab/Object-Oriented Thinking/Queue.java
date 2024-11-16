
public class Queue {
	private int[] elements;
	private int size;
	Queue() {
		elements = new int[8];
	}
	public void enqueue(int v) {
		if (size >= elements.length)
			doubleSize();
		elements[size++] = v;
	}
	public int dequeue() {
		size--;
		int r = elements[0];
		siftElements();
		return r;
	}
	public boolean empty() {
		return size == 0;
	}
	public int getSize() {
		return size;
	}
	public void doubleSize() {
		int[] temp = new int[elements.length * 2];
		System.arraycopy(elements, 0, temp, 0, size);
		elements = temp;
	}
	public void siftElements() {
		for (int i = 0; i < elements.length - 1; i++)
			elements[i] = elements[i + 1];
		elements[elements.length - 1] = 0;
	}

}
