public class Ex13 
{
    //class TestAdresseWeb {}
    public static void main(String[] args) {
        AdresseWeb adresse1 = new AdresseWeb("https", "supersite.fr", "/rep1/rep2/index.html");
        AdresseWeb adresse2 = new AdresseWeb("supersite.fr", "/rep1/rep2/index.html");
        AdresseWeb adresse3 = new AdresseWeb("supersite.fr");

        System.out.println(adresse1.toString());
        System.out.println(adresse2.toString());
        System.out.println(adresse3.toString());
        }
}

class AdresseWeb {
    private String protocole;
    private String domaine;
    private String chemin;

    // 1er constructeur avec tous les paramètres
    public AdresseWeb(String protocole, String domaine, String chemin) {
        this.protocole = protocole;
        this.domaine = domaine;
        this.chemin = chemin;
    }

    // 2e constructeur avec 2 paramètres --> surcharge
    public AdresseWeb(String domaine, String chemin) {
        this("http", domaine, chemin);
    }

    // 3e constructeur avec 1 parametre --> surcharge
    public AdresseWeb(String domaine) {
        this("http", domaine, "");
    }

    // Afficher le message
    public String toString() {
        return protocole + "://www." + domaine + chemin;
    }
}
//Q.2 - La surchage permet de crée plusieurs constructeurs dans une classe avec des signatures differentes. On peut donc cree et utiliser les objets de differente manieres selon nos besoins.

//Q.2 - this() permet de réduire le code d'initialisation commun dans chaque constructeurs. Cela rend le code plus court, lisible et pratique.