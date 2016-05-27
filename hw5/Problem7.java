import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Problem7 implements Runnable {
    static Map<Integer, Set<Integer>> data = new HashMap<>();

    private Integer key;

    Problem7(Integer key){
        this.key = key;
    }

    public void run(){
        Set<Integer> initialChild = data.get(key);
        Set<Integer> connected = new HashSet<>(initialChild);

        for(Integer key2: data.keySet()){
            if(key.equals(key2) || connected.contains(key2)){
                continue;
            }
            Set<Integer> values = data.get(key2);
            boolean intersected = false;
            for(Integer value: values){
                if(initialChild.contains(value)){
                    intersected = true;
                    break;
                }
            }

            if(intersected){
                connected.add(key2);
            }
        }

        System.out.printf("%d\t%d\n", key, connected.size());
    }

    public static void main(String[] args){
        try {
            BufferedReader br = new BufferedReader(new FileReader(args[0]));
            String line;
            while ((line = br.readLine()) != null){
                String[] parts = line.split("\t");
                int key = Integer.parseInt(parts[0]);
                int value = Integer.parseInt(parts[1]);

                data.putIfAbsent(key, new HashSet<>());

                Set<Integer> vals = data.get(key);
                vals.add(value);
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        ExecutorService pool = Executors.newFixedThreadPool(4);

        for(Integer key : data.keySet()){
            pool.execute(new Problem7(key));
        }
    }
}

