package assi;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;


public class DeadLock {
	static int n, m;
	static int [] available;
	static int [][] max;
	static int [][] allocation;
	static int [][] need;
	static int [] work;
	static boolean [] finish;
	static String command;
	
	public static void printCurrentState() {
        System.out.println("P_ID      Max       Allocation   Need       Available");
        for (int i = 0; i < n; i++) {
        	System.out.print("P" + (i) + "  	  ");
            for (int j = 0; j < m; j++) {
                System.out.print(max[i][j] + " ");   
            }
            System.out.print("    ");
            for (int j = 0; j < m; j++) {
                System.out.print(allocation[i][j] + " ");
            }
            System.out.print("       ");
            for (int j = 0; j < m; j++) {
                System.out.print(need[i][j] + " ");
            }
            System.out.print("     ");
            if (i == 0)
            for (int j = 0; j < m; j++) {
                System.out.print(available[j] + " ");
            }
            System.out.println();
        }
	}
	
	public static void releaseResource(String command) {
	    // necessary variables and containers
	    StringTokenizer st = new StringTokenizer(command); // command parser
	    String temp; // for cutting each token
	    ArrayList<Integer> my = new ArrayList<Integer>(); // storing amounts
	    while (st.hasMoreTokens()) {
	        temp = st.nextToken();
	        System.out.println(temp);
	        if (Character.isDigit(temp.charAt(0)))
	        	my.add(Integer.valueOf(temp));
	    }
	    
	    // now I've got the process number at index 0
	    // and the amount of each resource to release
	    // all stored in the array list
	    int processNumber = my.get(0);
	    for (int j = 0; j < m; j++) {
	    	if (allocation[processNumber][j] >= my.get(j + 1)) {
	    		allocation[processNumber][j] -= my.get(j + 1);
	    		available[j] += my.get(j + 1);
	    	} else {
	    		available[j] -= allocation[processNumber][j];
	    		allocation[processNumber][j] = 0;
	    	}
	    }	    
	}
	
	public static boolean needed_is_ok(int i) {
		for (int j = 0; j < m; j++)
			if (need[i][j] > work[j])
				return false;
		return true;
	}
	
	public static boolean safetyAlgorithm() {
		for (int i = 0; i < m; i++)
			work[i] = available[i];
		
		for (int i = 0; i < n; i++)
			finish[i] = false;
		
		for (int i = 0; i < n; i++)
			if (finish[i] == false && needed_is_ok(i)) {
				for (int j = 0; j < m; j++)
					work[j] += allocation[i][j];
				finish[i] = true;
				i = -1;
			}

		for (int i = 0; i < n; i++) 
			if (finish[i] == false)
				return false;
		return true;
	}
	
	public static void requestResource(String command) {
	    // necessary variables and containers
	    StringTokenizer st = new StringTokenizer(command); // command parser
	    String temp; // for cutting each token
	    int processNumber;
	    ArrayList<Integer> my = new ArrayList<Integer>(); // storing amounts
	    while (st.hasMoreTokens()) {
	        temp = st.nextToken();
	        if (Character.isDigit(temp.charAt(0)))
	        	my.add(Integer.valueOf(temp));
	    }
	    processNumber = my.get(0);
	    
	    for (int i = 0; i < m; i++) {
	    	if (my.get(i + 1) > need[processNumber][i]) {
	    		System.out.println("P " + processNumber +  "has exceeded its maximum claim ,, request rejected");
	    		return;
	    	}
	    }
	    
	    for (int i = 0; i < m; i++) {
	    	if (my.get(i + 1) > available[i]) {
	    		System.out.println("P " + processNumber + " Must wait, since resources are not available");
	    		return;
	    	}
	    }
	    
	    for (int i = 0; i < m; i++)  {
	    	available[i] -= my.get(i + 1);
	    	allocation[processNumber][i] += my.get(i + 1);
	    	need[processNumber][i] -= my.get(i + 1);
	    }
	    
	    if (safetyAlgorithm()) {
	    	System.out.println("Request Done Successfully ...");
	    } else {
		    for (int i = 0; i < m; i++)  {
		    	available[i] += my.get(i + 1);
		    	allocation[processNumber][i] -= my.get(i + 1);
		    	need[processNumber][i] += my.get(i + 1);
		    }
		    System.out.println("P " + processNumber + " Must wait, since request is unsafe");
	    }
	}
	
	public static int commandParser(String command) {
	    
	    if (command.equalsIgnoreCase("*"))
	        return 1;
	    else if (command.startsWith("RL"))
	        return 2;
	    else if (command.startsWith("RQ"))
	        return 3;
        else if (command.startsWith("quit"))
            return 4;
        return -1;

	}
	
	public static void prepareDataStructures() {
		available = new int [m];
		max = new int [n][m];
		allocation = new int [n][m];
		need = new int [n][m];
		work = new int[m];
		finish = new boolean[n];
	    for (int i = 0; i < n; i++)
	    	finish[i] = false;

	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream("input.txt"));
		System.out.println("Enter Number of Processes: ");
		n = in.nextInt();
		System.out.println("... Done ... ");
		System.out.println("Enter Number of Resource Types: ");
		m = in.nextInt();
		System.out.println("... Done ... ");
		
		// initializing data structures with specified sizes
		prepareDataStructures(); 
		
		System.out.println("Reading Input ... ");
		System.out.println("-- Reading Process Needs ... ");
		for (int i = 0; i < n; i++) {
//			System.out.print("P" + " " + (i + 1) + " ");
			for (int j = 0; j < m; j++) {	
				max[i][j] = need[i][j] = in.nextInt();
			}
//			System.out.println();
		}
		
		System.out.println("--Reading Processes Needs Succeeded ...");
		System.out.println("Enter Available Resources");
		for (int i = 0; i < m; i++) {
		    available[i] = in.nextInt();
		}
		// user manual for commands and their parameters
        System.out.println("Reading Input Succeeded ...");
        System.out.println("--------------");
        System.out.println("Commands List: ");
        System.out.println("--------------");
        System.out.println("*                            : Show the current state information");
        System.out.println("RL <process#> <r1> <r2> <r3> : Release Command");
        System.out.println("RQ <process#> <r1> <r2> <r3> : Request Command");
        System.out.println("quit                         : Exit Command");
        
        Scanner cin = new Scanner(System.in);
        while (true) {
            System.out.println("Enter a Command: ");
            command = cin.nextLine();
            int what = commandParser(command);
            if (what == 1) {
                // show the current state information
                printCurrentState();
            } else if (what == 2) {
                // release command
            	releaseResource(command);
            } else if (what == 3) {
                // request command
            	requestResource(command);
            } else if (what == 4) {
                // Exit command
                System.out.println("Good bye ... ");
                break;
            } else if (what == -1) {
                System.out.println("Invalid Command .. !!");
            }
        }
		in.close();
		cin.close();
	}
}	
