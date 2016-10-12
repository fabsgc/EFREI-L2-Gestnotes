<include src="include/header"/>

<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
			<th class="small">Situation</th>
		<tr>
	</thead>
	<tbody>
		<if condition="count($students) > 0">
			<foreach loop="$students as $data">
				<tr>
					<td>{$data['id']}</td>
					<td>{$data['personDetail']['firstName']} {$data['personDetail']['name']}</a></td>
					<td <if condition="studentHasBadMarks($marks, $data['id'])">class="red"<else/>class="green"</if>></td>
				</tr>
			</foreach>
		<else/>
			<tr>
				<td colspan="3" class="empty">Aucun élève</td>
			<tr>
		</if>
	<tbody>
</table>

<?php
	function studentHasBadMarks($marks, $student)
	{
		foreach ($marks as $key => $value) {
			if($student == $value['student']['id'] && $value['value'] < 10)
			{
				return true;
			}
		}

		return false;
	}
?>

<include src="include/footer"/>