public class Costume extends TheatricalThings {
    protected String color;
    protected int size;
    protected int price;

    Costume(String color, int size, int price) {
        this.color = color;
        this.size = size;
        this.price = price;
    }

    @Override
    public void print() {
        System.out.println("����: " + color);
        System.out.println("������: " + size);
    }

    @Override
    public int getPrice() {
        return price;
    }
}
