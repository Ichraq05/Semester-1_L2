package Ex20;

public class Point {
    private double posx, posy;

    public Point(int posx, int posy){
        this.posx = posx;
        this.posy = posy;
    }
    
    public Point (){
        this.posx = Math.random() * 9;
        this.posy = Math.random() * 9;
    }

    public String toString (){

        return "(" + String.format("%.1f",posx) + ", " + String.format("%.1f",posy) + ")" ;
    }

    // Méthode, calculer la distance entre deux points
    public double distance(Point p) {
        double xA = posx;
        double yA = posy;
        double xB = p.posx;
        double yB = p.posy;

        double distance = Math.sqrt(Math.pow(xB - xA, 2) + Math.pow(yB - yA, 2));
        return distance;
    }

    // Méthode, déplacer le point
    public void deplaceToi(int newx, int newy) {
        posx = newx;
        posy = newy;
    }

}
