public abstract class Props implements TheatricalThings {
    protected int hazardLevel;
    protected int serviceLife;
    protected int periodOfUse;
    protected int price;
    protected boolean status;

    protected void securityCheck () {
        if(periodOfUse >= serviceLife && hazardLevel > 2) {
            status = false;
        }
    }

    protected void printProps() {
        System.out.println("Уровень опасности: " + hazardLevel);
        System.out.println("Срок службы: " + serviceLife);
        System.out.println("Период использования: " + periodOfUse);
        System.out.println("Цена: " + price);
        if(status) {
            System.out.println("Статус: используется\n");
        }
        else {
            System.out.println("Статус: списано\n");
        }
    }

    public int getPrice() {
        return price;
    }
}
