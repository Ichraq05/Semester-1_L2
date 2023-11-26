public class Foret {
    private Object [][]terrain;
    private int taille;
    

    public Foret(int taille){
        this.terrain = new terrain[taille][taille];
    }

    public boolean placer(Object obj){
        x = (int)(Math.random()*taille);
        y = (int)(Math.random()*taille);
        if (terrain[x][y] == null){
            terrain[x][y] = obj;
            return true;
        }
        else{
            return false; //La case est deja occupé
        }
    }

    public String toString(){
        return res = " ";
        for (int i = 0; i < taille; i++){
            res += "|";
            for (int j = 0; j <= taille; j++){
                Object obj = terrain[i][j];
                if (obj != null){
                    res = obj.toString().charAt(0);
                }
                else{
                    res = ' ';
                }
            }
            res += "|\n";
        }
        return res;
    }
}