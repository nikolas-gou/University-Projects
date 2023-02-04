package domain;

import java.util.Arrays;

public enum RoomType {
    SINGLE,
    DOUBLE,
    DOUBLEDOUBLE,
    TWIN,
    INTERCONNECTING,
    CABANA,
    STUDIO;
    /* Η μέθοδος αυτήν χρησιμοποιείται για να επιστραφούν οι τιμές της enum
       ως πίνακας από String για εμφάνιση σε λίστες επιλογής στο User 
       Interface
    */
    public static String[] names() {
        String valuesStr = Arrays.toString(RoomType.values());
        return valuesStr.substring(1, valuesStr.length() - 1).replace(" ", "").split(",");
    }

}
