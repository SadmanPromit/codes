<?php
header("Content-type: text/xml");

$names = array("Anna", "Brittany", "Cinderella", "Diana", "Eva", "Fiona", "Gunda", "Hege", "Inga", "Johanna", "Kitty",
  "Linda", "Nina", "Ophelia", "Petunia", "Amanda", "Raquel", "Cindy", "Doris", "Eve", "Evita", "Sunniva",
  "Tove", "Unni", "Violet", "Liza", "Elizabeth", "Ellen", "Wenche", "Vicky");

$q = $_REQUEST["q"];

echo "<?xml version='1.0' encoding='UTF-8'?>";
echo "<names>";
foreach ($names as $name) {
  if (stripos($name, $q) === 0) {
    echo "<name>$name</name>";
  }
}
echo "</names>";
?>
