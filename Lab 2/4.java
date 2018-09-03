package lab2;
import java.util.*;
import java.io.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
public class Graph
{
	static int V=5;
	static int[][] field;

	public static void main(String[] args) {
        Scanner in = null;
        
        try {
            in = new Scanner(new FileReader("file.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
       
             
        for (int i = 1; i <V; i++) {
            for (int j = 1; j < V; j++) {
                field[i][j] = in.nextInt();
            }
        }


       if (isBipartite(field))
				System.out.println("BIPARTITE");
				else
				System.out.println("NOPARTITE");


    }
    public static boolean dfs(int field[][], int c[], int u)
	{
		
		for(int i=0;i<V;i++)
			{
					if(c[i]==-1 && field[u][i]==1)
						{
						c[i]=1-c[u];
						dfs(field,c,i);
					}
					else if(c[i]==c[u] && field[u][i]==1)
						return false;
				}
				return true;
	}
   	
	public static boolean isBipartite(int field[][])
	{
		
		int c[] = new int[V];
		for (int i = 0; i < V; i++)
			c[i] = -1;
	
		c[0]=1;
		if(dfs(field,c,0))
			return true;
		else
			return false;
	}
	

}