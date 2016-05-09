import java.io.*;
import java.util.*;

public class Problem5{

	public static void main(String[] args) {
		int N = 5105039;
		String path = "../web-Google.txt";
		File file = new File(path);
		String[] data = new String[N];
		String[] id = new String[N];
		int[] num = new int[N];

		try {
			BufferedReader br = new BufferedReader(new FileReader(file));
			String line;
			int i = 0;
			while ((line = br.readLine()) != null) {
				String[] parts = line.split("\t");
				data[i] = parts[1];
				i++;
			}
			br.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Arrays.sort(data);
		int k = 0, count = 0;
		String temp = " ";
		for(int j = 0; j < data.length; j++) {
			if(data[j].equals(temp)) {
				num[k-1] = ++count;
			}
			else {
				count = 1;
				temp = data[j];
				id[k] = data[j];
				num[k] = count;
				k++;
			}
		}
		for(int j = 0; j < k; j++) {
			System.out.println(id[j] + "\t" + num[j]);
		}
	}
}
