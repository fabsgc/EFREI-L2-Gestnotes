<include src="include/header"/>

<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
		<tr>
	</thead>
	<tbody>
		<if condition="count($groups) > 0">
			<foreach loop="$groups as $data">
				<tr>
					<td>{$data['id']}</td>
					<td><a href="/teacher/mark/group/{$data['id']}">{$data['name']}</a></td>
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