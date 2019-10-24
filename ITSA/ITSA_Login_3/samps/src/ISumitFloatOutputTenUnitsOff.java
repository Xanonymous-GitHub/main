import java.io.*;

//
// File:    ISumit.java
// Purpose: to sum the integers from stdin but produce an answer which is 10 units off from correct
// (for testing purposes).

// Author:  pc2@ecs.csus.edu or http://www.ecs.csus.edu/pc2
// 
// Wed 22 Feb 2017 15:52
// 
// $Id: isumit.java 1962 2009-11-25 03:42:12Z boudreat $
//

public class ISumitFloatOutputTenUnitsOff {
    public static void main(String[] args) 
    {
	try
	{	
		BufferedReader br = new BufferedReader (
			new InputStreamReader (System.in), 1);
		
		String line;
		int sum = 0;
		int rv = 0;
		while((line = br.readLine()) != null) 
		{			
			rv = new Integer(line.trim()).intValue();
			if (rv > 0)
				sum = sum + rv;
			// System.out.println(line);
		}
		System.out.print("The sum of the integers is ");
		System.out.println(new Double(sum-10));
	}
	catch(Exception e)
	{
		System.out.println("Possible trouble reading stdin");
		System.out.println("Message: "+ e.getMessage());
	}			
    }
}

// eof isumit.java $Id: isumit.java 1962 2009-11-25 03:42:12Z boudreat $

