package Ex20;

public class TestTriangle
{
    public static void main(String[] args) {
        Point p1 = new Point();
        Point p2 = new Point();

        System.out.println(p1.toString());
        System.out.println(p2.toString());

        double distance = p1.distance(p2);

        System.out.println(String.format("Distance entre les 2 points : %.1f", distance));
    }
}