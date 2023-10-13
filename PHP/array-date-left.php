<?php
$koneksi=mysqli_connect('localhost','root','');
mysqli_select_db($koneksi,'mydb');

$sql = 'select * from test';
$query = mysqli_query($koneksi,$sql);
$result = mysqli_fetch_all($query);

$jumlahkolom = 5;
$jumlahdata = mysqli_num_rows($query);
$jumlahbaris = ceil($jumlahdata/$jumlahkolom);

echo '<table border=1>';
$awalbaris = 0;
$akhirbaris = $jumlahkolom;

for($a=1;$a<$jumlahbaris+1;$a++){
	echo '<tr>';
	for ($b=$awalbaris;$b<$akhirbaris;$b++){
		if (isset($result[$b][1])) {
			echo '<td>'.$result[$b][1].'</td>';
		}
	}
	$awalbaris+=$jumlahkolom;
	$akhirbaris = $awalbaris + $jumlahkolom;
	echo '</tr>';
}
echo '</table>'


?>
