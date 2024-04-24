package java_final_review;

import java.util.ArrayList;

public class collections {
    public static void main(String[] args) {
        ArrayList<pair> arr = new ArrayList<>();

        arr.add(new pair(4, 4));
        arr.add(new pair(1, 4));
        arr.add(new pair(1, 3));
        arr.add(new pair(0, 2));

        arr.sort(null);

        for (pair p: arr) {
            System.out.println(p);
        }

    }
}
