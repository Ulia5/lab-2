public class Costume implements TheatricalThings {
    protected String color;
    protected int size;
    protected int price;

    Costume(String color, int size, int price) {
        this.color = color;
        this.size = size;
        this.price = price;
    }

    public void printCostume() {
        System.out.println("����: " + color);
        System.out.println("������: " + size);
        System.out.println("����: " + price);
    }

    public int getPrice() {
        return price;
    }
}
