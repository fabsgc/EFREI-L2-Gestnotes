<include src="include/header"/>

<if condition="$report == true">
	<a href="/student/mark/report" class="button right">Afficher le bulletin</a>
</if>

<table class="table">
	<thead>
		<tr>
			<th>Matière</th>
			<th>Coefficient</th>
			<th>Note</th>
		<tr>
	</thead>
	<tbody>
		<if condition="count($marks) > 0">
			<foreach loop="$marks as $data">
				<tr>
					<td>
						{$data['course']['name']} : <?php getMarkType($data['type']) ?>
					</td>
					<td>{$data['coeff']}</td>
					<td>{$data['value']}</a></td>
				</tr>
			</foreach>
		<else/>
			<tr>
				<td colspan="3" class="empty">Aucune note</td>
			<tr>
		</if>
	<tbody>
</table>

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
?>

<include src="include/footer"/>