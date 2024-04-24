package java_final_review;

import java.util.Objects;

public class pair implements Comparable<pair>{
    private final int x;
    private final int y;

    public pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        pair pair = (pair) o;
        return x == pair.x && y == pair.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }

    @Override
    public String toString() {
        return this.x + " " + this.y;
    }

    @Override
    public int compareTo(pair other) {
        if (this.x != other.x) {
            return Integer.compare(this.x, other.x);
        } else {
            return Integer.compare(this.y, other.y);
        }
    }
}
