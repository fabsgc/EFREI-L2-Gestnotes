<include src="include/header"/>
<?php
	$moyenne = 0;

	foreach ($courses as $key => $course) {
		$moyenne += moyenne($course, $marks);
	}

	$moyenne = $moyenne / count($courses);
?>
<h3>Moyenne générale : {$moyenne}/20</h3>

<foreach loop="$courses as $course">
	<h4>{$course['name']} (<?php echo moyenne($course, $marks) ?>/20)</h4>

	<table class="table">
		<thead>
			<tr>
				<th>Matière</th>
				<th>Coefficient</th>
				<th>Note</th>
			<tr>
		</thead>
		<tbody>
			<foreach loop="$marks as $data">
				<if condition="$data['course']['id'] == $course['id']">
					<tr>
						<td>
							{$data['course']['name']} : <?php getMarkType($data['type']) ?>
						</td>
						<td>{$data['coeff']}</td>
						<td>{$data['value']}</a></td>
					</tr>
				</if>
			</foreach>
		<tbody>
	</table>
</foreach>

<?php
	function getMarkType($type)
	{
		switch ($type) {
			case "1":
				echo "CE";
			break;

			case "2":
				echo "DE";
			break;

			case "3":
				echo "TP";
			break;

			case "4":
				echo "Projet";
			break;
		}
	}

	function moyenne($course, $marks)
	{
		$moyenne = 0;

		foreach ($marks as $key => $value) {
			if($value['course']['id'] == $course['id'])
			{
				$moyenne += $value['value'] * $value['coeff'];
			}
		}

		return $moyenne;
	}
?>

<include src="include/footer"/>