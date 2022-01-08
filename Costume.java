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
        System.out.println("Цвет: " + color);
        System.out.println("Размер: " + size);
        System.out.println("Цена: " + price);
    }

    public int getPrice() {
        return price;
    }
}
