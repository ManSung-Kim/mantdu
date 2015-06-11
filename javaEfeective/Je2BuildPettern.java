package com.example.javaeffective;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

	TextView mText;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		mText = (TextView)findViewById(R.id.textBoard);
		
		Je2BuildPettern food1 = new Je2BuildPettern.Builder(100, 99).build();
		mText.setText("food1 info\n"+food1.getInfo());
		Je2BuildPettern food2 = new Je2BuildPettern.Builder(100, 99)
										.miwon(50)
										.rice(35)
										.build();
		mText.append("\n\nfood2 info\n"+food2.getInfo());
		
	}

}
