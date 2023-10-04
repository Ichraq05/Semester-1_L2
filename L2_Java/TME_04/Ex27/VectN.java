package L2_Java.TME_04.Ex27;

public class VectN {
    private int []tab;

    //Q.2 - Passer le constructeur en private.
    public VectN(int n){
    this.tab = new int [n];
    }

    public VectN(int n, int valMax){
        this(n);
        for (int i = 0; i < n; i++){
            tab[i] = (int)(Math.random()*(valMax+1));
        }
    }

    public VectN(){
        this(5, 9);
    }

    public VectN(int a, int b, int c){
        this.tab = new int[]{a,b,c};
    }

    public void affiche(){
        for(int x : this.tab){
            System.out.print(x + ", ");
        }
        System.out.println();
    }

    public int somme(){
        int res = 0;
        for(int x : this.tab){
            res += x ;
        }
        return res;
    }

    public String toString(){
        for(int x : this.tab){
            System.out.print();
        }
        System.out.println();
    }


    public static void main(String[] args) {
        VectN v1 = new VectN(3);
        VectN v2 = new VectN(3,5);
        VectN v3 = new VectN();
        VectN v4 = new VectN(1,2,3);

        v1.affiche();
        v2.affiche();
        v3.affiche();
        v4.affiche();

        System.out.println(v2.somme());
    }
}
