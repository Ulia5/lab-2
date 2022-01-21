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
        System.out.println("Цвет: " + color);
        System.out.println("Размер: " + size);
    }

    @Override
    public int getPrice() {
        return price;
    }
}
