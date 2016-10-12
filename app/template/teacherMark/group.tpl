<include src="include/header"/>

<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
		<tr>
	</thead>
	<tbody>
		<if condition="count($courses) > 0">
			<foreach loop="$courses as $data">
				<tr>
					<td>{$data['id']}</td>
					<td><a href="/teacher/mark/course/{$get['id']}/{$data['id']}">{$data['name']}</a></td>
				</tr>
			</foreach>
		<else/>
			<tr>
				<td colspan="2" class="empty">Aucun groupe</td>
			<tr>
		</if>
	<tbody>
</table>

<include src="include/footer"/>