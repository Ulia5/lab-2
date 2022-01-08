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
        System.out.println("������� ���������: " + hazardLevel);
        System.out.println("���� ������: " + serviceLife);
        System.out.println("������ �������������: " + periodOfUse);
        System.out.println("����: " + price);
        if(status) {
            System.out.println("������: ������������\n");
        }
        else {
            System.out.println("������: �������\n");
        }
    }

    public int getPrice() {
        return price;
    }
}
