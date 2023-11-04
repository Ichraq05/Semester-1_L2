package L2_Java.TME_04.Ex28;

public class TestPile {
    public static void main(String[] agrs){
        Pile p1 = new Pile(3);
        System.out.println(p1.toString());

        Assiette a = new Assiette();

        p1.empiler(a);
        p1.empiler(a);
        p1.empiler(a);
        System.out.println(p1.toString());

        p1.depiler();
        System.out.println(p1.toString());

        Assiette nv_a1 = new Assiette(28);
        Assiette nv_a2 = new Assiette(32);
        p1.empiler(nv_a1);
        p1.empiler(nv_a2);
        System.out.println(p1.toString());

        p1.depiler();
        p1.depiler();
        p1.depiler();
        p1.depiler();
        System.out.println(p1.toString());
    }
}