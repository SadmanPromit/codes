<?php
echo "<table>";
echo "<table border='1'>";
for ($i = 1; $i <= 6; $i++) {
    echo "<tr>";
    for ($j = 1; $j <= 5; $j++) {
        $k = $i * $j;
        echo "<td>$i * $j = $k</td>";
    }
    echo "</td>";
}
echo "</table>";
?>