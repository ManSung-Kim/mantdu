package dbg_log;

import android.util.Log;

public final class Dlog {
	private static String tag = "mstag";
	
	public void setTag(String tag) {
		Dlog.tag = tag;
	}
	
	/*public static int d(String msg) { // only String class
		return Log.d(tag, msg);
	}*/
	
	public static <T extends Object> int d(T msg) { // Generic
		return Log.d(tag, msg+"");
	}
}
