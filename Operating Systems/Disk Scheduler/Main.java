package disk_scheduler;


import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class Main {
	
	

	public static int get_min_index(ArrayList<Integer> reqs, int currentHeadPointerValue) {
		int min = Math.abs(currentHeadPointerValue - reqs.get(0));
		int index = 0;
		for (int i = 1; i < reqs.size(); ++i) {
			int temp =  Math.abs(currentHeadPointerValue - reqs.get(i));
			if (temp < min) {
				min = temp;
				index = i;
			}
		}
		return index;
	}
	
	public static void first_come_first_serve_algorithm(ArrayList<Integer> reqs, int currentHeadPointerValue) {
		int headMovements = 0;
		for (int i = 0; i < reqs.size(); ++i) {
			headMovements += Math.abs(currentHeadPointerValue - reqs.get(i));
			currentHeadPointerValue = reqs.get(i);
			System.out.print(reqs.get(i) + " ");
		}
		System.out.println("\nTotal Head Movements = " + headMovements + "\n\n");
	}

	public static void shortest_seek_time_first_algorithm(ArrayList<Integer> reqs, int currentHeadPointer) {
		ArrayList<Integer> tempArray = new ArrayList<Integer>();
		for (int i = 0; i < reqs.size(); ++i)
			tempArray.add(reqs.get(i));
		
		ArrayList<Integer> order = new ArrayList<Integer>();
		order.add(currentHeadPointer);
		int currentRequest = currentHeadPointer;
		int headMovements = 0;
		while (tempArray.size() > 0) {
			// now current head pointer has the new value
			int index = get_min_index(tempArray, currentRequest);
			currentRequest = tempArray.get(index);
			tempArray.remove(index);
			order.add(currentRequest);
			System.out.print(currentRequest + " ");
		}
		for (int i = 1; i < order.size(); ++i)
			headMovements += Math.abs(order.get(i) - order.get(i - 1));
		System.out.println("\nTotal head Movements = " + headMovements + "\n\n");
	}
	
	public static void scan_scheduling_algorithm(ArrayList<Integer> reqs, int currentHeadPointer) {
		ArrayList<Integer> temp = new ArrayList<Integer>();
		for (int i = 0; i < reqs.size(); ++i)
			temp.add(reqs.get(i));
		
		Collections.sort(temp);
		int i;
		int index = 0;
		int headMovements = 0;
		ArrayList<Integer> order = new ArrayList<Integer>();
		order.add(currentHeadPointer);
		
		for (i = 0; i < temp.size(); ++i) {
			if (temp.get(i) > currentHeadPointer) {
				index = i - 1;
				break;
			}
		}
		
		for (i = index; i >= 0; --i) {
			order.add(temp.get(i));
			System.out.print(temp.get(i) + " ");
		}
		
		order.add(0);
		System.out.print(0 + " ");
		
		for (i = index + 1; i < temp.size(); ++i) {
			order.add(temp.get(i));
			System.out.print(temp.get(i) + " ");
		}
		for (i = 1; i < order.size(); ++i)
			headMovements += Math.abs(order.get(i) - order.get(i - 1));
		System.out.println("\nTotal Head Movements = " + headMovements + "\n\n");
	}
	
	public static void circular_scan_scheduling_algorithm(ArrayList<Integer> reqs, int currentHeadPointer) {
		ArrayList<Integer> temp = new ArrayList<Integer>();
		for (int i = 0; i < reqs.size(); ++i)
			temp.add(reqs.get(i));
		
		int index = 0;
		int i;
		int headMovements = 0;
		Collections.sort(temp);
		for (i = 0; i < temp.size(); ++i) {
			if (temp.get(i) > currentHeadPointer) {
				index = i;
				break;
			}
		}
		
		
		for (i = index; i < temp.size(); ++i) {
			headMovements += Math.abs(currentHeadPointer - temp.get(i));
			currentHeadPointer = temp.get(i);
			System.out.print(temp.get(i) + " ");
		}
			
		headMovements += Math.abs(currentHeadPointer - 199);
		headMovements += 199;
		currentHeadPointer = 0;
		System.out.print(199 + " " + 0 + " ");
		
		for (i = 0; i < index; ++i) {
			headMovements += Math.abs(currentHeadPointer - temp.get(i));
			currentHeadPointer = temp.get(i);
			System.out.print(temp.get(i) + " ");
		}
		
		System.out.println("\nTotal Head Movements = " + headMovements + "\n\n");
	}
	
	public static void look_scheduling_algorithm(ArrayList<Integer> reqs, int currentHeadPointer) {
		ArrayList<Integer> temp = new ArrayList<Integer>();
		for (int i = 0; i < reqs.size(); ++i)
			temp.add(reqs.get(i));

		Collections.sort(temp);
		
		int index = 0;
		int headMovements = 0;
		for (int i = 0; i < temp.size(); ++i) {
			if (temp.get(i) > currentHeadPointer) {
				index = i - 1;
				break;
			}
		}
		
		for (int i = index; i >= 0; --i) {
			headMovements += Math.abs(currentHeadPointer - temp.get(i));
			currentHeadPointer = temp.get(i);
			System.out.print(temp.get(i) + " ");
		}
		
		for (int i = index + 1; i < temp.size(); ++i) {
			headMovements += Math.abs(currentHeadPointer - temp.get(i));
			currentHeadPointer = temp.get(i);
			System.out.print(temp.get(i) + " ");
		}
		System.out.println("\nTotal Head Movements = " + headMovements + "\n\n");
	}

	public static void circular_look_scheduling_algorithm(ArrayList<Integer> reqs, int currentHeadPointer) {
		ArrayList<Integer> temp = new ArrayList<Integer>();
		for (int i = 0; i < reqs.size(); ++i)
			temp.add(reqs.get(i));
		int index = 0;
		Collections.sort(temp);
		for (int i = 0; i < temp.size(); ++i) {
			if (temp.get(i) > currentHeadPointer) {
				index = i;
				break;
			}
		}
		
		int headMovements = 0;
		for (int i = index; i < temp.size(); ++i) {
			headMovements += Math.abs(currentHeadPointer - temp.get(i));
			currentHeadPointer = temp.get(i);
			System.out.print(temp.get(i) + " ");
		}
			
		
		for (int i = 0; i < index; ++i) {
			headMovements += Math.abs(currentHeadPointer - temp.get(i));
			currentHeadPointer = temp.get(i);
			System.out.print(temp.get(i) + " ");
		}
		
		System.out.println("\nTotal Head Movements = " + headMovements + "\n\n");
	}
	
	
	public static void main(String []args) throws IOException {
		
		ArrayList<Integer> requests = new ArrayList<Integer>();
		Scanner cin = null;
		try {
			cin = new Scanner(new FileInputStream("disk_access_requests.txt"));			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		int diskHeadPointer = cin.nextInt();
		String line = cin.nextLine(); // ignore the initial buffer
		line = cin.nextLine(); // read the input
	
		// now divide the string into integers
		// representing the requests
		String tokens;
		StringTokenizer st = new StringTokenizer(line);
		while (st.hasMoreTokens()) {
			tokens = st.nextToken();
			requests.add(Integer.valueOf(tokens));
		}
		
		System.out.println("Current Head Pointer is on: " + diskHeadPointer + "\n\n");
		
		
		/*
		 * Algorithms
		 */

		System.out.println("First Come First Serve Scheduling");
		first_come_first_serve_algorithm(requests, diskHeadPointer);
		
		System.out.println("Shortest Seek Time First Scheduling");
		shortest_seek_time_first_algorithm(requests, diskHeadPointer);
		
		System.out.println("Scan Scheduling");
		scan_scheduling_algorithm(requests, diskHeadPointer);
		
		System.out.println("Circular Scan Scheduling");
		circular_scan_scheduling_algorithm(requests, diskHeadPointer);
		
		System.out.println("Look Scheduling");
		look_scheduling_algorithm(requests, diskHeadPointer);
		
		System.out.println("Circular Look Scheduling");
		circular_look_scheduling_algorithm(requests, diskHeadPointer);
		
		cin.close();
	}
}
