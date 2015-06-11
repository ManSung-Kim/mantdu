package com.example.javaeffective;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

import android.util.Log;

public class Je2PrivateClassInvoker {
	
	public Je2PrivateClassInvoker() {
		
		// origin
		PrivateSingleton originInstance = PrivateSingleton.getInstance();
		Log.d("mstag","Origin1 : "+originInstance.getTest());
		PrivateSingleton originInstance2 = PrivateSingleton.getInstance();
		Log.d("mstag","Origin2 : "+originInstance2.getTest());
		
		
		// invoke
		Constructor<?> con = PrivateSingleton.class.getDeclaredConstructors()[0];
		con.setAccessible(true);
		try {
			PrivateSingleton newInstance1 = (PrivateSingleton) con.newInstance();
			Log.d("mstag","invoke : "+newInstance1.getTest());
		} catch (Exception e) {
			
		}
	}

}

class PrivateSingleton {
	private static final PrivateSingleton pInstance = new PrivateSingleton();
	
	public static PrivateSingleton getInstance() {
		return pInstance;
	}
	
	public String getTest() {
		return ""+this;
	}
}
