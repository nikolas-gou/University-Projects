package domain;

public class Client {
    private String name;
    private String telephone;

    public Client(String name, String telephone) {
        this.name = name;
        this.telephone = telephone;
    }

    public String getName() {
        return name;
    }

    public String getTelephone() {
        return telephone;
    }

}
