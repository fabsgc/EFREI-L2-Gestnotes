<include src="include/header"/>

<table class="table">
	<thead>
		<tr>
			<th>Matière</th>
			<th>CE</th>
			<th>DE</th>
			<th>TP</th>
			<th>Projet</th>
		<tr>
	</thead>
	<tbody>
		<if condition="count($courses) > 0">
			<foreach loop="$courses as $course">
				<tr>
					<td>
						{$course['name']}
					</td>
					<td>{$course['coeffCe']}</td>
					<td>{$course['coeffDe']}</td>
					<td>{$course['coeffTp']}</td>
					<td>{$course['coeffProject']}</td>
				</tr>
			</foreach>
		<else/>
			<tr>
				<td class="empty" colspan="5">Aucun cours</td>
			</tr>
		</if>
	<tbody>
</table>

<include src="include/footer"/>