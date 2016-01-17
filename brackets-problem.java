/*
* Problem:
* Input: m(a(bc)(d(e(fgh)i)j)k)n
* output:
* group 0: m(a(bc)(d(e(fgh)i)j)k)n
* group 1:(a(bc)(d(e(fgh)i)j)k)
* group 2:(bc)
* group 3:(d(e(fgh)i)j)
* group 4:(e(fgh)i)
* group 5:(fgh)
*/
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
public class Sajal_323_Project1
{
	public static void main(String[] args) 
	{

		try
		{
			Scanner input = new Scanner(new FileReader(args[0])); //to read input file
			PrintWriter Output = new PrintWriter(new FileOutputStream(args[1]));// to read output file

			while(input.hasNextLine()) {
				
				String inp = input.nextLine();// to create string for input
				Output.println("group 0: " + inp);// to print output for the given input
				int cnt =1; // to initialize counter for the no of groups in one line
				int walk = -1, walkend=0; // walk and walkend to indicate the beginning and end of indexes for each character in a string 
				int count=0, flag = 0; // initialize count to count the no of brackets and flag is to determine the group of a line 
				
				while(walk<=inp.length()-1)
				{
					count = 0;
					flag = 0;
					
					for(int i= ++walk; i<=inp.length()-1; i++)// to walk through each character of a string to find matching brackets
					{
						if(inp.charAt(i) == '(')
						{
							if(count == 0)
							{
								walk =i;
							}
							count++;
						}
						
						if((inp.charAt(i)== ')') && (count != 0))
						{
							count--;
							if(count == 0 )
							{
								walkend = i;
								flag =1;
								break;
							}
						}
					}
					
					if((count == 0) && flag ==1) // print when the group is found
					{
						Output.print("group " +cnt+ ":" ); 
						for (int j= walk; j<= walkend ; j++  )
						{

							Output.print(inp.charAt(j) );
						}
						Output.println();
						cnt++;

					}
				}
			}
			input.close();
			Output.close();
		}
		catch(Exception e) {

			System.err.println(e);
		}
	}
}
