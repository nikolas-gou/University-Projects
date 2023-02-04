package domain;

import domainInfrastructure.Period;
import java.util.ArrayList;
import java.util.List;

public class Room {
    private List<Reservation> reservations;
    private RoomType roomType;
    private int roomNumber;
    
    public Room() {
        reservations = new ArrayList<>();
    }
    public Room(RoomType roomType) {
        reservations = new ArrayList<>();
        this.roomType=roomType;
    }

    public List<Reservation> getReservations() {
        return reservations;
    }

    public void addReservation(Reservation reservation) {
        this.reservations.add(reservation);
    }

    public RoomType getRoomType() {
        return roomType;
    }

    public void setRoomType(RoomType roomType) {
        this.roomType = roomType;
    }

    public int getRoomNumber() {
        return roomNumber;
    }

    public void setRoomNumber(int roomNumber) {
        this.roomNumber = roomNumber;
    }
    
    public boolean available(Period period) {
        for (Reservation rsv : reservations) {
            if (rsv.overlaps(period)) {
                return false;
            }
        }
        return true;
    }
}
