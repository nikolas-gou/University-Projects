package domain;

import domainInfrastructure.Period;

public class Reservation {
    private Period period;
    private Client client;
    private Room room;

    public Reservation(Period period, Client client, Room room) {
        this.period = period;
        this.client = client;
        this.room = room;
    }

    public Client getClient() {
        return client;
    }

    public Period getPeriod() {
        return period;
    }

    public Room getRoom() {
        return room;
    }

    public void setPeriod(Period period) {
        this.period = period;
    }

    public void setClient(Client client) {
        this.client = client;
    }

    public void setRoom(Room room) {
        this.room = room;
    }

    public boolean overlaps(Period period) {
        return this.period.overlaps(period);
    }
}
