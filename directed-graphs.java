/*
* Write a code to compute total number of directed grpahs for the given number of vertices.
*/
/**
 * @author Sajal Zaki
 * 
 */

import java.io.*;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintWriter;
import java .util.Scanner;
public class Sajal323_Project2 
{
	public static void main(String[] args)
	{
		try
		{
			Scanner input = new Scanner(new FileReader(args[0])); //to read input file
			PrintWriter Output = new PrintWriter(new FileOutputStream(args[1]));// to read output file

			while(input.hasNextInt()) 
			{
				int m, c, d; //initializing integers for the length of adjacency matrices
				m = input.nextInt();// taking number of vertex from user

				int v[][] = new int[m][m];// creating 2 dimensional array for adjacency matrix
				int k; // saving module value for tthe conversion of binary 
				int count =0; // counting number of matrices for directed graphs
				
				Output.println("Directed matrix for vertex :" +m);
				
				//going through the powerset of vertices of directed graph
				for(int f = 0; f < Math.pow(2, Math.pow(m,2)); f++)
				{
					Output.println("matrix no : " + ++count);
					Output.println();
					// conversion of base 10 into binary
					d=f;
					k=d%2;
					c=k;
					// 2 dimensional array for adjacency matrix
					for(int i=0; i<m; i++)
					{
						for(int j=0; j<m; j++)
						{
							if(c!=k)
							{
								c=d%2;
							}
							Output.print(v[i][j]=c); // printing rows and columns of matrices
							c= d-c;
							c=c/2;
							d=c;
						}

						Output.print("\n");
					}
					Output.println();
				}
				Output.println();
			}
			input.close(); 
			Output.close();
		}
		catch(Exception e) 
		{

			System.err.println(e);
		}

	}


}
