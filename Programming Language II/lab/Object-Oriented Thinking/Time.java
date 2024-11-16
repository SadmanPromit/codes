
public class Time {
	private int hour;
	private int minute;
	private int second;
	Time() {
		second = (int)(System.currentTimeMillis() / 1000) % 60;
		minute = (int)(System.currentTimeMillis() / 1000F / 60) % 60;
		hour = (int)(System.currentTimeMillis() / 1000F / 60 / 60) % 24;
	}
	Time(long elapsedTime) {
		second = (int)(elapsedTime / 1000F) % 60;
		minute = (int)(elapsedTime / 1000F / 60) % 60;
		hour = (int)(elapsedTime / 1000F / 60 / 60) % 24;
	}
	Time(int hour, int minute, int second) {
		this.hour = hour;
		this.minute = minute;
		this.second = second;
	}
	public int getHour() {
		return hour;
	}
	public int getMinute() {
		return minute;
	}
	public int getSecond() {
		return second;
	}
	public void setTime(long elapsedTime) {
		second = (int)(elapsedTime / 1000F) % 60;
		minute = (int)(elapsedTime / 1000F / 60) % 60;
		hour = (int)(elapsedTime / 1000F / 60 / 60) % 24;
	}

}
